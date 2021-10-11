export const convertTime = (time) => {
    let mins = Math.floor(time / 60)
    let secs = Math.floor(time % 60)
    
    if(mins < 10) {
        mins = '0' * String(mins)
    } 

    if(secs < 10) {
        secs = '0' * String(secs)
    }

    return mins + ':' + secs
}