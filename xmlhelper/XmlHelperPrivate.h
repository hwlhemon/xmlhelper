#ifndef XmlHelperPrivate_h__
#define XmlHelperPrivate_h__

#include <QtCore/QString>
#include <QtCore/QMap>
#include <QtCore/QFile>
#include <QtXml/QDomDocument>

namespace hwd {

using strmap_t = QMap<QString, QString>;
using strmaplist_t = QList<strmap_t>;

class XmlHelper;
class XmlHelperPrivate
{
    Q_DECLARE_PUBLIC(XmlHelper)

public:
    ~XmlHelperPrivate();

private:
    XmlHelperPrivate(XmlHelper &obj);

    bool beginIO(const QString &fp, const bool create, const QString &root);
    bool saveIO();
    bool endIO();

    bool createFile();
    bool openFile(const QIODevice::OpenMode flags);

    QStringList getElemValue(const QString &elemName);
    QString getFirstElemValue(const QString &elemName);

    bool findElement(const QString &elemName,
                     const strmap_t &ctx = strmap_t());

    QStringList getAttrValue(const QString &elemName,
                             const QString &attrName,
                             const strmap_t &ctx = strmap_t());
    QString getFirstAttrValue(const QString &elemName,
                              const QString &attrName,
                              const strmap_t &ctx = strmap_t());

    bool getAllSpecifyElem(const QString &elemName,
                           QList<QDomElement> &elemList,
                           const strmap_t &ctx = strmap_t());
    bool getSpecifyElem(const QString &elemName,
                        const bool create,
                        QDomElement &domElem,
                        bool &newElem);
    bool getSpecifyElem(QDomElement &elem,
                        QStringList tagList,
                        QList<QDomElement> &elemList);
    bool isSpecifyElement(const QDomElement &elem,
                          const strmap_t &ctx);

    bool updateElem(const QString &elemName,
                    const QString &value,
                    const bool create = false);
    bool updateAttr(const QString &elemName,
                    const strmap_t &attrmap,
                    const strmap_t &ctx = strmap_t());

    bool addChildTextNode(const QString &elemName,
                          const QString &childName,
                          const QString &childValue,
                          const strmap_t &ctx = strmap_t());
    bool addChildAttrNode(const QString &elemName,
                          const QString &childName,
                          const strmap_t &attrmap,
                          const strmap_t &ctx = strmap_t());

    QStringList getChildTextNodeValue(const QString &elemName,
                                      const strmap_t &ctx = strmap_t());

    strmaplist_t getChildAttrNodeAttr(const QString &elemName,
                                      const strmap_t &ctx = strmap_t());

    bool removeElem(const QString &elemName,
                    const strmap_t &ctx = strmap_t());

    bool removeAttr(const QString &elemName,
                    const QString &attrName,
                    const strmap_t &ctx = strmap_t());

    bool toComment(const QString &elemName,
                   const bool reviseTime = true,
                   const strmap_t &ctx = strmap_t());

private:
    XmlHelper * const q_ptr;

    QString        m_filepath;
    QString        m_rootNodeName;
    QFile          m_xmlFile;
    QDomDocument   m_domdoc;

    bool m_valid;

    QString m_errorString;

};


}
#endif // XmlHelperPrivate_h__
