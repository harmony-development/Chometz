#pragma once

#include <QString>
#include <QJsonValue>
#include <QJsonObject>

namespace Chometz {

class Storer
{
public:
    virtual void store(const QString& key, QJsonValue value) = 0;
};

class Loader
{
public:
    virtual QJsonValue load(const QString& key) = 0;
    virtual bool has(const QStringList& keys) = 0;
};

class JSONLoadStore final : public Storer, public Loader
{
    QJsonObject obj;

public:
    void store(const QString& key, QJsonValue value) override;
    QJsonValue load(const QString& key) override;
    bool has(const QStringList& keys) override;
};

};


