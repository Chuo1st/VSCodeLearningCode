const reg2 = /\p{Unified_Ideograph}/u
const reg = /京+/

console.log(reg2.test('北京'))

const cities = ['北京', '南京', '广州']
for (let i = 0; i < cities.length; ++i)
{
    if (reg.test(cities[i]))
    {
        console.log(cities[i])
    }
}