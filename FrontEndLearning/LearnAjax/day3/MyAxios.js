function MyAxios(config)
{
    const promise = new Promise((resolve, reject) => {
        const xhr = new XMLHttpRequest()
        if (config.params)
        {
            const getParamsHelper = new URLSearchParams(config.params)
            const paramsString = decodeURIComponent(getParamsHelper.toString())
            config.url += `?${paramsString}`
        }
        xhr.open(config.method || 'GET', config.url)
        xhr.addEventListener('loadend', () => {
            // 判断http状态码来判断请求有无异常
            if (xhr.status >= 200 && xhr.status < 300)
            {
                resolve(JSON.parse(xhr.response))
            }
            else
            {
                reject('HTTP error: ' + xhr.status)
            }
        })
        if (config.data)
        {
            xhr.setRequestHeader('Content-Type', 'application/json')
            xhr.send(JSON.stringify(config.data))
        }
        else
        {
            xhr.send()
        }
    })
    return promise
}