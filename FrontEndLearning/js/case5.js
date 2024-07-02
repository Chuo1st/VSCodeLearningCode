const singers = ['jay chou', 'andy lou', 'jack chang', 'lesily', 'david tao']
let min = 0
let max = 2

const first = Math.floor(Math.random() * singers.length)
singers.splice(first, 1)
let second = Math.floor(Math.random() * singers.length)
singers.splice(second, 1)
let third = Math.floor(Math.random() * singers.length)

const span1 = document.getElementById('one')
const span2 = document.getElementById('two')
const span3 = document.getElementById('three')
span1.innerHTML = `${singers[first]}`
span2.innerHTML = `${singers[second]}`
span3.innerHTML = `${singers[third]}`


min = 1
max = 22
function GetRandom(left, right)
{
    const randomNum = Math.floor(Math.random() * (right - left) + 1)
    return randomNum
}
const randomNum = GetRandom(min,max)
const img = document.querySelector('.pic')
const index = randomNum >= 10 ? randomNum : '0' + randomNum
img.src = `../source/case4_images/${index}.jpg`