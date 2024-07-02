
using Microsoft.Extensions.DependencyInjection;
namespace DI
{
    public class LearnDI
    {
        public static void Test()
        {
            ServiceCollection service = new ServiceCollection();
            // 先注册服务
            
            using (ServiceProvider provider = service.BuildServiceProvider())
            {
                
            }
            
        }
    }
}