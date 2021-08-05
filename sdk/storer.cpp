#include "storer_p.h"

namespace Chometz {

QJsonValue JSONLoadStore::load(const QString &key)
{
    return obj[key];
}

void JSONLoadStore::store(const QString &key, QJsonValue value)
{
    obj[key] = value;
}

bool JSONLoadStore::has(const QStringList &keys)
{
    for (const auto& it : keys) {
        if (!obj.keys().contains(it)) {
            return false;
        }
    }

    return true;
}

};
