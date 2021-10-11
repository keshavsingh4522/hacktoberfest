import './style.css'
import { convertTime } from './utils'

const AudioContext = window.AudioContext ?? window.webkitAudioContext
const audioCtx = new AudioContext()

const audioElement = document.getElementById('audio');
const playBtn = document.getElementById('playbtn');
const volumeSlider = document.getElementById('volume');
const seeker = document.getElementById('seeker');
const time = document.getElementById('time')
const duration = document.getElementById('duration')

const audioSource = audioCtx.createMediaElementSource(audioElement)

window.addEventListener('load', () => {
  time.textContent = convertTime(audioElement.currentTime)
  duration.textContent = convertTime(audioElement.duration)
})

// Play/Pause the audio
playBtn.addEventListener('click', (event) => {
  const targetEl = event.target

  // check if context is in suspended state (autoplay policy)
  if (audioCtx.state === 'suspended') {
    audioCtx.resume()
  }

  // if song is stopped, play it
  if (playBtn.getAttribute('class') === 'paused') {
    audioElement.play()
    targetEl.setAttribute('class', 'playing')
  } else if (playBtn.getAttribute('class') === 'playing') {
    audioElement.pause()
    targetEl.setAttribute('class', 'paused')
  }
})

audioElement.addEventListener('ended', () => {
  playBtn.setAttribute('class', 'paused')
})

audioElement.addEventListener('timeupdate', () => {
  seeker.value = audioElement.currentTime
  time.textContent = convertTime(audioElement.currentTime)
})

// Volume control
const gainNode = audioCtx.createGain();

volumeSlider.addEventListener('input', () => {
	gainNode.gain.value = volumeSlider.value;
});

// Seekder control
seeker.setAttribute('max', audioElement.duration)

seeker.addEventListener('input', () => {
  audioElement.currentTime = seeker.value
})

// connect our graph
audioSource.connect(gainNode).connect(audioCtx.destination);