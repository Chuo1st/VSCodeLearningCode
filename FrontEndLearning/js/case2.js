
let products = ['iphone', 'redmi', 'iqoo', 'hornor', 'oppo']
let sales = []
for (i = 0; i < products.length; ++i)
{
    sales.push(+prompt(`enter the sales of ${products[i]}: `))
}

document.write(`<div class = "box">`)
for(i = 0; i < sales.length; ++i)
{
    document.write(`
        <div style= "height: ${sales[i]}px;">
            <span>${sales[i]}</span>
            <h4>${products[i]}</h4>
        </div>
    `)
}
document.write(`</div>`)