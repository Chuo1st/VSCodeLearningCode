
// 工厂模式
namespace SimpleFactory
{
    public class SimplePhoneFactory
    {
        public IPhone MakePhone(string company)
        {
            if (company.Trim().ToLower() == "miphone")
            {
                return new MiPhone();
            }else{
                return new ApplePhone();
            }
        }
    }

    public interface IPhone{
        void Make();
    }

    public class MiPhone:IPhone{
        public void Make()
        {
            Console.WriteLine("mi phone");
        }
    }

    public class ApplePhone:IPhone{
        public void Make()
        {
            Console.WriteLine("apple phone");
        }
    }
}

// 将生产任务交给不同的派生类工厂。这样不用通过指定类型来创建对象了
namespace MethodFactory
{
    public interface IPhone
    {
        void Make();
    }

    public class MiPhone:IPhone{
        public void Make()
        {
            Console.WriteLine("mi phone");
        }
    }

    public class ApplePhone:IPhone{
        public void Make()
        {
            Console.WriteLine("apple phone");
        }
    }

    public interface IFactory
    {
        IPhone CreatFactory();
    }

    public class MiFactory:IFactory
    {
        public IPhone CreatFactory()
        {
            return new MiPhone();
        }
    }

    public class AppleFactory:IFactory
    {
        public IPhone CreatFactory()
        {
            return new ApplePhone();
        }
    }
}


namespace AbstractFactory{
    public interface IMobile
    {
        public string Mac{get;set;}

        void Call(string number);
    }

    public interface IComputer
    {
        public string CPU{get;set;}

        public int Memory{get;set;}

        void Run();
    }

    public abstract class AbstractFactory
    {
        public abstract IComputer GetComputer(string str);

        public abstract IMobile GetMobile(string str);
    }

    public class ComputerFactory:AbstractFactory
    {
        public override IComputer GetComputer(string computerBrand){return null;}

        public override IMobile GetMobile(string str){return null;}
    }

    public class MobileFactory:AbstractFactory
    {
        public override IComputer GetComputer(string computerBrand){return null;}

        public override IMobile GetMobile(string str){return null;}
    }

    public class FactoryProducer
    {
        public static AbstractFactory GetFactory(string factoryType)
        {
            return null;
        }
    }
}

namespace MethodFactoryNS{
    public interface IProduct{
        public void ShowInfo();
    }

    public class Wine:IProduct
    {
        public void ShowInfo()
        {
            Console.WriteLine("it's a wine");
        }
    }

    public class Fruit:IProduct
    {
        public void ShowInfo()
        {
            Console.WriteLine("it's a fruit");
        }
    }

    public abstract class MethodFactory{
        public abstract IProduct CreateOperation();
    }

    public class FruitFactory:MethodFactory
    {
        public override IProduct CreateOperation()
        {
            return new Fruit();
        }
    }

    public class WineFactory:MethodFactory{
        public override IProduct CreateOperation()
        {
            return new Wine();
        }
    }
}