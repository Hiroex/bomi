#include "osdtheme.hpp"
#include "misc/json.hpp"
#include "misc/record.hpp"

#define DO(func) {\
    func(font); \
    func(scale); \
    func(underline); \
    func(bold); \
    func(strikeout); \
    func(italic); \
    func(color); \
    func(styleColor); \
    func(style); }

auto OsdTheme::save(Record &r, const QString &group) const -> void
{
    r.beginGroup(group);
#define WRITE(a) r.write(a, #a);
    DO(WRITE)
#undef WRITE
    r.endGroup();
}

auto OsdTheme::load(Record &r, const QString &group) -> void
{
    r.beginGroup(group);
#define READ(a) r.read(a, #a);
    DO(READ)
#undef READ
    r.endGroup();
}

auto OsdTheme::toJson() const -> QJsonObject
{
    JsonObject json;
    json["font"] = font;
    json["scale"] = scale;
    json["underline"] = underline;
    json["bold"] = bold;
    json["strikeout"] = strikeout;
    json["italic"] = italic;
    json["color"] = color;
    json["styleColor"] = styleColor;
    json["style"] = style;
    return json.qt();
}

auto OsdTheme::fromJson(const QJsonObject &qjson) -> OsdTheme
{
    OsdTheme theme;
    const JsonObject json(qjson);
    json.get("font", theme.font);
    json.get("scale", theme.scale);
    json.get("underline", theme.underline);
    json.get("bold", theme.bold);
    json.get("strikeout", theme.strikeout);
    json.get("italic", theme.italic);
    json.get("color", theme.color);
    json.get("styleColor", theme.styleColor);
    json.get("style", theme.style);
    return theme;
}

/******************************************************************************/

OsdThemeObject::OsdThemeObject(QObject *parent)
    : QObject(parent)
{

}