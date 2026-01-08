import HomeJokeSection from '@/components/sections/Home/JokeSection'
import { Button } from '@/components/ui/button'
import { getJoke } from '@/services/joke-api'
import { jokeResponsePayloadData } from '@/services/joke-api/types'
import Image from 'next/image'


const getRandomJoke = async () => {
  const joke = await getJoke();
  if (joke) return joke;
  throw new Error("error getting error");
}

export default async function Home() {
  const joke = await getRandomJoke() as jokeResponsePayloadData[];
  return (

    <div className='container mx-auto fixed inset-0 flex flex-col justify-center items-center'>
      <HomeJokeSection joke={joke} />
    </div>

  )
}
