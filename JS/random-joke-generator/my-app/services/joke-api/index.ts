import axios from "axios";

export const BASE_URL = "https://api.api-ninjas.com/v1/jokes?limit=1";

export const jokeAPIInstance = new URL(BASE_URL);

export const getJoke = async () => {
  try {
    const response = await axios.get(jokeAPIInstance.href, {
      headers: {
        "X-Api-Key": process.env.NEXT_PUBLIC_JOKE_API_KEY,
      },
    });
    const data = await response.data;
    return data;
  } catch (error) {
    throw error;
  }
};
