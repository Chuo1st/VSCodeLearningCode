
let price = prompt('pleas enter the price: ')
let num = prompt('please enter the num')
let addr = prompt('please enter the addresse')
document.write(`
    <table>
        <tr>
            <th>商品名称</th>
            <th>商品价格</th>
            <th>商品数量</th>
            <th>总价</th>
            <th>收货地址</th>
        </tr>
        <tr>
            <th>redmi k30s</th>
            <th>${price}</th>
            <th>${num}</th>
            <th>${price * num}</th>
            <th>${addr}</th>
        </tr>
    </table>
`)