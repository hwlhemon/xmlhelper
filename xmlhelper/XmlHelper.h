#ifndef XmlHelper_h__
#define XmlHelper_h__

#include <QtCore/QScopedPointer>
#include <QtCore/QString>
#include <QtCore/QMap>

namespace hwd {

using strmap_t = QMap<QString, QString>;
using strmaplist_t = QList<strmap_t>;

class XmlHelperPrivate;
class XmlHelper
{
    Q_DECLARE_PRIVATE(XmlHelper)

public:
    XmlHelper();
    ~XmlHelper();

    /**
     * @brief         start read or write
     * @param fp      xml file path
     * @param create  if file not exist, create or not
     * @param root    root node name
     * @return        success or not
    */
    bool beginIO(const QString &fp,
                 const bool create,
                 const QString root = "Root");

    /**
     * @brief save cached
    */
    bool saveIO();

    /**
     * @brief end read, write flag and clear cache
    */
    bool endIO();

    /**
     * @brief
     * @param    elemName node name, split with "/"
     * @return   all value
    */
    QStringList getElemValue(const QString &elemName);
    QString getFirstElemValue(const QString &elemName);

    /**
     * @brief
     * param elemName  node name, split with "/"
     * param attrName  attribute name
     * param ctx       query context
     * return          all eligible attribute values
    */
    QStringList getAttrValue(const QString &elemName,
                             const QString &attrName,
                             const strmap_t &ctx = strmap_t());
    QString getFirstAttrValue(const QString &elemName,
                              const QString &attrName,
                              const strmap_t &ctx = strmap_t());

    /**
    * @brief add element or update element value
    * @param elemName  node name, split whit "/"
    * @param value     node value
    * @param create    if node not exist, create ?
    * @return          success or not
    */
    bool updateElem(const QString &elemName,
                    const QString &value,
                    const bool create = false);

    /**
    * @brief updateAttr
    * @param elemName    node name, split with "/"
    * @param attrmap     new attribute map
    * @param ctx         query context, if empty, revise all same name node
    * @return            success or not
    */
    bool updateAttr(const QString &elemName,
                    const strmap_t &attrmap,
                    const strmap_t &ctx = strmap_t());

    /**
    * @brief addChildTextNode
    * @param elemName     node name, split with "/"
    * @param childName    child node name
    * @param childValue   child node value
    * @param ctx          query context map, if empty, add to all same node
    * @return             success or not
    */
    bool addChildTextNode(const QString &elemName,
                          const QString &childName,
                          const QString &childValue,
                          const strmap_t &ctx = strmap_t());

    /**
    * @brief addChildAttrNode
    * @param elemName      split whit "/"
    * @param childName     child node name
    * @param attrmap       child node attribute map
    * @param ctx           query context map, if empty, add to all same node
    * @return              success or not
    */
    bool addChildAttrNode(const QString &elemName,
                          const QString &childName,
                          const strmap_t &attrmap,
                          const strmap_t &ctx = strmap_t());

    /**
    * @brief getChildTextNodeValue
    * @param strElem    node name split with"/"
    * @param varCtx     query context map
    * @return           result map list
    */
    QStringList getChildTextNodeValue(const QString &elemName,
                                      const strmap_t &ctx = strmap_t());

    /**
    * @brief getChildAttrNodeAttr
    * @param strElem    node name, split with "/"
    * @param varCtx     query context map
    * @return           result string map list
    */
    strmaplist_t getChildAttrNodeAttr(const QString &elemName,
                                      const strmap_t &ctx = strmap_t());

    /**
     * @brief  remove elem  If the element parent has no children, remove
    */
    bool removeElem(const QString &elemName,
                    const strmap_t &ctx = strmap_t());

    bool removeAttr(const QString &elemName,
                    const QString &attrName,
                    const strmap_t &ctx = strmap_t());

    /**
    * @brief toComment  only can comment which element has no child
    * @param elemName   node name split with "/"s
    * @param reviseTime add  comment time
    * @param ctx        comment context map
    * @return
    */
    bool toComment(const QString &elemName,
                   const bool reviseTime = true,
                   const strmap_t &ctx = strmap_t());

    QString getErrorString();

private:
    QScopedPointer<XmlHelperPrivate> d_ptr;
};

}
#endif // XmlHelper_h__
