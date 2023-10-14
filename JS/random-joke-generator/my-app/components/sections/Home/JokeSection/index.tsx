"use client";
import React, { useState } from 'react'
import { Button } from '@/components/ui/button';
import { Card } from '@/components/ui/card';
import { getJoke } from '@/services/joke-api';
import { jokeResponsePayloadData } from '@/services/joke-api/types';

interface HomeJokeSectionProps {
    joke: jokeResponsePayloadData[]
}

const HomeJokeSection: React.FC<HomeJokeSectionProps> = (props) => {
    const [joke, setJoke] = useState<string>(props.joke[0].joke)
    const getNewJoke = async () => {
        try {
            const data = await getJoke() as jokeResponsePayloadData[];
            setJoke(data[0].joke)
        } catch (error) {
            console.log(error)
        }
    }
    return (
        <Card className='p-4 shadow-md flex flex-col justify-center items-center gap-2'>
            <h1 className='text-7xl'>😂</h1>
            <p>{joke}</p>
            <Button onClick={getNewJoke}>Get joke</Button>
        </Card>
    )
}

export default HomeJokeSection