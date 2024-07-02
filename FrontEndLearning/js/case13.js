const inputName = document.querySelector('.uname')
const inputAge = document.querySelector('.age')
const selectGender = document.querySelector('.gender')
const inputSalary = document.querySelector('.salary')
const selectCity = document.querySelector('.city')
const form = document.querySelector('.info')
const tbody = document.querySelector('tbody')
const studentArray = []

form.addEventListener('submit', (e)=>{
    e.preventDefault()
    if (inputName.value && inputAge.value && inputSalary.value)
    {
        const student = {
            id: `${studentArray.length + 1}`,
            name: `${inputName.value}`,
            age: `${inputAge.value}`,
            gender: `${selectGender.value}`,
            salary: `${inputSalary.value}`,
            city: `${selectCity.value}`
        }
        studentArray.push(student)
        Render()
    }
    else
    {
        alert('请填写完整')
    }
    form.reset()
})

tbody.addEventListener('click', (e)=>{
    if (e.target.tagName === 'A')
    {
        const id = e.target.parentNode.parentNode.children[0].cellIndex
        studentArray.splice(id, 1)
        tbody.removeChild(e.target.parentNode.parentNode)
    }
})

function Render()
{
    tbody.innerHTML = ''
    for (let i = 0; i < studentArray.length; ++i)
    {
        const tr = document.createElement('tr')
        tr.innerHTML = `
            <td>${i + 1}</td>
            <td>${studentArray[i].name}</td>
            <td>${studentArray[i].age}</td>
            <td>${studentArray[i].gender}</td>
            <td>${studentArray[i].salary}</td>
            <td>${studentArray[i].city}</td>
            <td>
                <a 'href = javascript:'>删除</a>
            </td>
        `
        tbody.appendChild(tr)
    }
}