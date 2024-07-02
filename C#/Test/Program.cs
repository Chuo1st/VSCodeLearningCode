
using System.Reflection;
using System.Runtime.InteropServices;
using Newtonsoft.Json;
using Newtonsoft.Json.Linq;
using System.Reflection.Emit;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices.Marshalling;
using System.Runtime.ExceptionServices;
using System.Text;
using System.Security.Cryptography.X509Certificates;
using FluentModbus;
using System.Net;

/*1. 动态生成方法 */

// 最后一个参数设置对应类的Type，就可以访问该类的私有成员了
DynamicMethod dynamicMethod = new DynamicMethod("DynamicMethodShow", null, new Type[0], typeof(Test));
MethodInfo methodInfo = typeof(Test).GetMethod("PrivateMethod", BindingFlags.Static | BindingFlags.NonPublic);
// 获取il代码生成器
ILGenerator gen = dynamicMethod.GetILGenerator();
 // gen执行的这写方法代表il指令的执行流, 代表这个动态生成方法的执行指令流
gen.EmitWriteLine("hello, this indication is excuted by DynamicMethodShow");
//gen.Emit(OpCodes.Call, methodInfo);
gen.Emit(OpCodes.Ret); // 方法返回
// 执行动态生成的方法
dynamicMethod.Invoke(null, null);

/*2. 评估栈 */
DynamicMethod dyMethod = new DynamicMethod("DynamicMethod1", null, null);
MethodInfo writelineInfo = typeof(Console).GetMethod("WriteLine", BindingFlags.Static|BindingFlags.Public, new Type[]{typeof(int)});
ILGenerator gen1 = dyMethod.GetILGenerator();
gen1.Emit(OpCodes.Ldc_I4, 12);
gen1.Emit(OpCodes.Ldc_I4, 8);
gen1.Emit(OpCodes.Add);
gen1.Emit(OpCodes.Call, writelineInfo);
gen1.Emit(OpCodes.Ret);
dyMethod.Invoke(null, null);

/*3. 动态生成方法的参数传递*/
DynamicMethod dyMethod2 = new DynamicMethod("DynamicMehod2", null, new Type[]{typeof(int), typeof(int)});
MethodInfo methodInfo2 = typeof(Console).GetMethod("WriteLine", BindingFlags.Static | BindingFlags.Public, new Type[]{typeof(int)});
ILGenerator gen2 = dyMethod2.GetILGenerator();
gen2.Emit(OpCodes.Ldarg_0);
gen2.Emit(OpCodes.Ldarg_1);
gen2.Emit(OpCodes.Mul);
gen2.Emit(OpCodes.Call, methodInfo2);
gen2.Emit(OpCodes.Ret);
dyMethod2.Invoke(null, new object[]{5, 3});

/*4. 动态方法中使用局部变量 */
DynamicMethod dyMethod3 = new DynamicMethod("DynamiMethod3", null, new Type[]{typeof(int), typeof(int)});
ILGenerator gen3 = dyMethod3.GetILGenerator();
LocalBuilder local1 = gen3.DeclareLocal(typeof(int));
LocalBuilder local2 = gen3.DeclareLocal(typeof(int));
gen3.Emit(OpCodes.Ldarg_0);
gen3.Emit(OpCodes.Stloc, local1);
gen3.Emit(OpCodes.Ldarg_1);
gen3.Emit(OpCodes.Stloc, local2);
gen3.Emit(OpCodes.Ldloc, local1);
gen3.Emit(OpCodes.Ldloc, local2);
gen3.Emit(OpCodes.Add);
gen3.Emit(OpCodes.Stloc, local1);
gen3.EmitWriteLine(local1);
gen3.Emit(OpCodes.Ret);
dyMethod3.Invoke(null, new object[]{60, 8});

/*5. 分支 */
/* 
    用il代码实现：
    int x = 5; 
    for (; x < 10; ++x) 
        Console.WriteLine(x.ToString());
*/
DynamicMethod dyMethod4 = new DynamicMethod("DynamicMethod4", null, null);
ILGenerator gen4 = dyMethod4.GetILGenerator();
LocalBuilder localx = gen4.DeclareLocal(typeof(int)); // int x;
gen4.Emit(OpCodes.Ldc_I4, 5); // 5入评估栈
gen4.Emit(OpCodes.Stloc, localx); // x = 5;
Label startLoop = gen4.DefineLabel();
Label endLoop = gen4.DefineLabel();
gen4.MarkLabel(startLoop);
    gen4.Emit(OpCodes.Ldc_I4, 10); // 评估栈底
    gen4.Emit(OpCodes.Ldloc, localx); // 评估栈顶
    gen4.Emit(OpCodes.Blt, endLoop); // 评估栈弹出顶部两个值，如果第一个值小于第二个值，则将控制权转移到目标指令：if (10 < x) >> 退出循环
    gen4.EmitWriteLine(localx); // Console.WriteLine(x.ToString());
    gen4.Emit(OpCodes.Ldc_I4, 1);
    gen4.Emit(OpCodes.Ldloc, localx);
    gen4.Emit(OpCodes.Add); // ++x;
    gen4.Emit(OpCodes.Stloc, localx);
    gen4.Emit(OpCodes.Br, startLoop); // 回到77行
gen4.MarkLabel(endLoop);
gen4.Emit(OpCodes.Ret);
dyMethod4.Invoke(null, null);




/*6. 实例化对象 */


public class Test
{
    public Test()
    {
        Console.WriteLine("Test");
    }

    public const int t = 1;
}


