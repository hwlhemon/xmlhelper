#include "XmlHelper.h"
#include "XmlHelperPrivate.h"

namespace hwd {


XmlHelper::XmlHelper()
    : d_ptr(new XmlHelperPrivate(*this))
{
}

XmlHelper::~XmlHelper()
{
}


bool XmlHelper::beginIO(const QString &fp,
                        const bool create,
                        const QString root)
{
    Q_D(XmlHelper);
    return d->beginIO(fp, create, root);
}

bool XmlHelper::saveIO()
{
    Q_D(XmlHelper);
    return d->saveIO();
}

bool XmlHelper::endIO()
{
    Q_D(XmlHelper);
    return d->endIO();
}

QStringList XmlHelper::getElemValue(const QString &elemName)
{
    Q_D(XmlHelper);
    return d->getElemValue(elemName);
}

QString XmlHelper::getFirstElemValue(const QString &elemName)
{
    Q_D(XmlHelper);
    return d->getFirstElemValue(elemName);
}

QStringList XmlHelper::getAttrValue(const QString &elemName,
                                    const QString &attrName,
                                    const strmap_t &ctx)
{
    Q_D(XmlHelper);
    return d->getAttrValue(elemName, attrName, ctx);
}

QString XmlHelper::getFirstAttrValue(const QString &elemName,
                                     const QString &attrName,
                                     const strmap_t &ctx)
{
    Q_D(XmlHelper);
    return d->getFirstAttrValue(elemName, attrName, ctx);
}

bool XmlHelper::findElement(const QString &elemName,
                            const strmap_t &ctx)
{
    Q_D(XmlHelper);
    return d->findElement(elemName, ctx);
}

bool XmlHelper::updateElem(const QString &elemName,
                           const QString &value,
                           const bool create)
{
    Q_D(XmlHelper);
    return d->updateElem(elemName, value, create);
}

bool XmlHelper::updateAttr(const QString &elemName,
                           const strmap_t &attrmap,
                           const strmap_t &ctx)
{
    Q_D(XmlHelper);
    return d->updateAttr(elemName, attrmap, ctx);
}

bool XmlHelper::addChildTextNode(const QString &elemName,
                                 const QString &childName,
                                 const QString &childValue,
                                 const strmap_t &ctx)
{
    Q_D(XmlHelper);
    return d->addChildTextNode(elemName, childName, childValue, ctx);
}

bool XmlHelper::addChildAttrNode(const QString &elemName,
                                 const QString &childName,
                                 const strmap_t &attrmap,
                                 const strmap_t &ctx)
{
    Q_D(XmlHelper);
    return d->addChildAttrNode(elemName, childName, attrmap, ctx);
}

QStringList XmlHelper::getChildTextNodeValue(const QString &elemName,
                                             const strmap_t &ctx)
{
    Q_D(XmlHelper);
    return d->getChildTextNodeValue(elemName, ctx);
}

strmaplist_t XmlHelper::getChildAttrNodeAttr(const QString &elemName,
                                             const strmap_t &ctx)
{
    Q_D(XmlHelper);
    return d->getChildAttrNodeAttr(elemName, ctx);
}

bool XmlHelper::removeElem(const QString &elemName,
                           const strmap_t &ctx)
{
    Q_D(XmlHelper);
    return d->removeElem(elemName, ctx);
}

bool XmlHelper::removeAttr(const QString &elemName,
                           const QString &attrName,
                           const strmap_t &ctx)
{
    Q_D(XmlHelper);
    return d->removeAttr(elemName, attrName, ctx);
}

bool XmlHelper::toComment(const QString &elemName,
                          const bool reviseTime,
                          const strmap_t &ctx)
{
    Q_D(XmlHelper);
    return d->toComment(elemName, reviseTime, ctx);
}

QString XmlHelper::getErrorString()
{
    Q_D(XmlHelper);
    return d->m_errorString;
}

}
