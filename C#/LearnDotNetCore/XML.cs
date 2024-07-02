
using System.Xml;
namespace MyXML{
    public class XMLSerializer
    {
        public static void LearnOperateXML()
        {
            XmlDocument xml = new XmlDocument();
            try
            {
                xml.Load("Test.xml");
                XmlElement? rootElement =  xml.DocumentElement;
                var nodes = rootElement.ChildNodes;
                var books = rootElement.SelectNodes("book");
            }
            catch (System.Exception)
            {
                
                throw;
            }

        }
    }
}