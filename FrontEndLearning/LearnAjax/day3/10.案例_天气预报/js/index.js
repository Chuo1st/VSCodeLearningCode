
// 默认先加载北京的天气
function GetWeatherInfo(cityName)
{
    axios({url:'https://hmajax.itheima.net/api/weather/city', params:{city:cityName}}).then(cityInfo => {
         // 获取对应城市的天气数据
         axios({url:'https://hmajax.itheima.net/api/weather', params:{city:`${cityInfo.data.data[0].code}`}}).then(weatherCast => {
            console.log(weatherCast)
            return weatherCast.data
         }).catch(err => {
           console.log(err)
           return null
         })
     }).catch(err => console.log(err))
}

// 渲染天气预报信息
function renderWeatherCast(weatherData)
{
    console.log(weatherData)
    renderTopBox({dateShort:weatherData.data.dateShort, dateLunar:weatherData.data.dateLunar, area:weatherData.data.area})
    renderWeatherBox({
        temperature:weatherData.data.temperature,
        psPm25:weatherData.data.psPm25,
        psPm25Level:weatherData.data.psPm25Level,
        weatherImg:weatherData.data.weatherImg,
        weather:weatherData.data.weather,
        windDirection:weatherData.data.windDirection,
        windPower:weatherData.data.windPower})
    renderTodayWeaher({
        weather:weatherData.data.todayWeather.weather,
        temNight:weatherData.data.todayWeather.temNight,
        temDay:weatherData.data.todayWeather.temDay,
        ultraviolet:weatherData.data.todayWeather.ultraviolet,
        humidity:weatherData.data.todayWeather.humidity,
        sunriseTime:weatherData.data.todayWeather.sunriseTime,
        sunsetTime:weatherData.data.todayWeather.sunsetTime
    })
    renderWeekWeather(weatherData.data.dayForecast)
}

// 渲染top-box
function renderTopBox(dataTopBox)
{
    Object.keys(dataTopBox).map((ele, index) => {
        const dom = document.querySelector(`.${ele}`)
        dom.innerHTML = dataTopBox[ele]
    })
}

//  渲染weaher-box
function renderWeatherBox(dataWeatherBox)
{
    Object.keys(dataWeatherBox).map((ele, index) => {
        const dom = document.querySelector(`.${ele}`)
        if (ele === 'weatherImg')
        {
            dom.src = dataWeatherBox[ele]
        }
        else{
            dom.innerHTML = dataWeatherBox[ele]
        }
    })
}

// 渲染today-weather
function renderTodayWeaher(dataTodayWeather)
{
    Object.keys(dataTodayWeather).map((ele, index) => {
        const dom = document.querySelector(`.${ele}`)
        dom.innerHTML = dataTodayWeather[ele]
    })
}

// 渲染week-weather-box
function renderWeekWeather(dataWeekWeather)
{
    const ulDom = document.querySelector('.week-wrap')
    let html = ''
    for (let i = 0; i < dataWeekWeather.length; ++i)
    {
        html += `<li class="item">
        <div class="date-box">
          <span class="dateFormat">${dataWeekWeather[i].dateFormat}</span>
          <span class="date">${dataWeekWeather[i].date}</span>
        </div>
        <img src=${dataWeekWeather[i].weatherImg} alt="" class="weatherImg">
        <span class="weather">${dataWeekWeather[i].weather}</span>
        <div class="temp">
          <span class="temNight">${dataWeekWeather[i].temNight}</span>-
          <span class="temDay">${dataWeekWeather[i].temDay}</span>
          <span>℃</span>
        </div>
        <div class="wind">
          <span class="windDirection">${dataWeekWeather[i].windDirection}</span>
          <span class="windPower">${dataWeekWeather[i].windPower}</span>
        </div>
      </li>`
    }
    ulDom.innerHTML = html
}