import discord
import os
import requests
import json
from alive import keep_alive

client = discord.Client()

@client.event
async def on_message(message):
  if message.author == client.user:
    return

  msg = message.content

  if msg.startswith('pls hello'):
    await message.channel.send("Hello Noob")
   
  elif msg.startswith('pls bye'):
    await message.channel.send("Bye! Get Lost")

  
keep_alive()
client.run(os.getenv('YOUR BOT TOKEN')
