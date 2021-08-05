#include "storer_p.h"

QJsonValue JSONLoadStore::load(const QString &key)
{
    return obj[key];
}

void JSONLoadStore::store(const QString &key, QJsonValue value)
{
    obj[key] = value;
}
