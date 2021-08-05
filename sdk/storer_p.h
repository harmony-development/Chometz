#pragma once

#include <QString>
#include <QJsonValue>
#include <QJsonObject>

class Storer
{
public:
    virtual void store(const QString& key, QJsonValue value) = 0;
};

class Loader
{
public:
    virtual QJsonValue load(const QString& key) = 0;
};

class JSONLoadStore final : public Storer, public Loader
{
    QJsonObject obj;

public:
    void store(const QString& key, QJsonValue value) override;
    QJsonValue load(const QString& key) override;
};


