
#include <QtCore/QCoreApplication>

#include "XmlHelper.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    hwd::XmlHelper xml;
    xml.beginIO("1.xml", true, "Root");
#if 0
    xml.updateElem("Registration", "", true);
    xml.addChildTextNode("Registration", "Static", "x");
    hwd::strmap_t attrmap = { {"uid", "test"}, { "index", "1x"} };
    xml.addChildAttrNode("Registration", "Static", attrmap);
    attrmap["index"] = "2x";
    xml.addChildAttrNode("Registration", "Static", attrmap);

    auto attrmap2 = attrmap;
    attrmap2["uid"] = "test2";
    xml.addChildAttrNode("Registration/Static", "Field", attrmap2, attrmap);
    xml.addChildTextNode("Registration/Static", "Field2", "xxx", attrmap);
#else
    hwd::strmap_t attrmap2;
    attrmap2["uid"] = "test";
    xml.removeElem("Registration/Static", attrmap2);
    //xml.removeAttr("Registration/Static", "index", attrmap2);
//     QStringList valList = xml.getElemValue("Registration/Static");
//     QStringList attrList = xml.getAttrValue("Registration/Static", "uid");
//     xml.toComment("Registration/Static", true);
#endif
    xml.saveIO();
    xml.endIO();
    return a.exec();
}
