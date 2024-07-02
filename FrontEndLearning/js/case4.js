let heros = [
    {
        name : 'hero1',
        src : '../source/case4_images/01.jpg'
    }
    ,
    {
        name : 'hero2',
        src : '../source/case4_images/02.jpg'
    }
    ,
    {
        name : 'hero3',
        src : '../source/case4_images/03.jpg'
    }
    ,
    {
        name : 'hero4',
        src : '../source/case4_images/04.jpg'
    }
    ,
    {
        name : 'hero5',
        src : '../source/case4_images/05.jpg'
    }
    ,
    {
        name : 'hero6',
        src : '../source/case4_images/06.jpg'
    }
    ,
    {
        name : 'hero7',
        src : '../source/case4_images/07.jpg'
    }
    ,
    {
        name : 'hero8',
        src : '../source/case4_images/08.jpg'
    }
    ,
    {
        name : 'hero9',
        src : '../source/case4_images/09.jpg'
    }
    ,
    {
        name : 'hero10',
        src : '../source/case4_images/10.jpg'
    }
    ,
    {
        name : 'hero11',
        src : '../source/case4_images/11.jpg'
    }
    ,
    {
        name : 'hero12',
        src : '../source/case4_images/12.jpg'
    }
    ,
    {
        name : 'hero13',
        src : '../source/case4_images/13.jpg'
    }
]

for (i = 0; i < heros.length; ++i)
{
    document.write(`                
        <li>
            <img src="${heros[i].src}" title="${heros[i].name}">
        </li>
`)
}