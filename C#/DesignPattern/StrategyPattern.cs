
// 策略模式
namespace StrategyPattern
{
    public interface ITransportStrategy
    {
        public void ArriveTarget(string start, string target);

        public float Cost();
    }

    public class PublicTransport:ITransportStrategy
    {
        public void ArriveTarget (string a, string b)
        {
            Console.WriteLine("public transport");
        }

        public float Cost()
        {
            return 2;
        }
    }

    public class RoadTransport:ITransportStrategy
    {
        public void ArriveTarget (string a, string b)
        {
            Console.WriteLine("RoadTransport");
        }

        public float Cost()
        {
            return 20;
        }
    }

    public class TransportContext
    {
        private ITransportStrategy? strategy = null;

        public void SetStrategy(ITransportStrategy s)
        {
            strategy = s;
        }

        public void DoSomething(string from, string to)
        {
            strategy?.ArriveTarget(from, to);
            strategy?.Cost();
        }
    }
}