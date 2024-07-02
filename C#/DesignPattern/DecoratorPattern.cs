
// 装饰器模式
namespace DecoratorPattern{
    
    public interface IDress{
        public void Dress();
    }

    public class Person:IDress
    {
        private string name;
        public Person(string name)
        {
            this.name = name;
        }

        public virtual void Dress()
        {
            Console.WriteLine($"{name}穿了 ");
        } 
    }

    public class TshirtDecorator:IDress
    {
        private IDress? dress;

        public void Dress()
        {
            dress?.Dress();
            Console.WriteLine("Tshirt ");
        }

        public void Decorate(IDress dress)
        {
            this.dress = dress;
        }
    }
}