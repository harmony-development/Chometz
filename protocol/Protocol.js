var File = require("qbs.File");
var FileInfo = require("qbs.FileInfo");
var Utilities = require("qbs.Utilities");
var TextFile = require("qbs.TextFile");

function hasEndingInTrailingBrace(str, substr) {
    var lines = str.split("\n")
    for (var i = 0; i < lines.length; i++) {
        var line = lines[i]

        if (line.contains(substr) && line.endsWith("{")) {
            return true
        }
    }
    return false
}

function getArtifacts(product, input) {
    var fpath = input.filePath.replace(product.protocolPath, product.buildDirectory)

    var artifacts = [{
        filePath: fpath.replace(".proto", ".pb.cc"),
        fileTags: ["cpp", "pb-cc"]
    },{
        filePath: fpath.replace(".proto", ".pb.h"),
        fileTags: ["hpp", "pb-h"]
    }]

    var file = new TextFile(input.filePath)
    var content = file.readAll()
    file.close()

    if (hasEndingInTrailingBrace(content, "message")) {
        artifacts.push({
            filePath: fpath.replace(".proto", ".hrpc.types.h"),
            fileTags: ["hpp", "hrpc-types"]
        })
    }

    if (hasEndingInTrailingBrace(content, "service")) {
        artifacts.push({
            filePath: fpath.replace(".proto", ".hrpc.client.cpp"),
            fileTags: ["cpp", "hrpc-client-cc"]
        })
        artifacts.push({
            filePath: fpath.replace(".proto", ".hrpc.client.h"),
            fileTags: ["hpp", "hrpc-client-h"]
        })
    }

    return artifacts
}
function prepare(protocolPath, product, input, outputs) {
    var command =
        new Command
            ( "protoc",
                [ "--proto_path=" + protocolPath
                , "--cpp_out=" + product.buildDirectory
                , "--hrpc_out=" + product.buildDirectory
                , "--hrpc_opt=qt_cpp_client"
                , "--experimental_allow_proto3_optional"
                , input.filePath
                ]
            )
    command.highlight = "codegen"
    command.description = "hrpc for " + input.fileName

    return [command]
}
