# A discord.py file by @Yogi

import discord
from discord import message
from discord import colour
from discord.embeds import Embed
from discord.ext import commands
from discord.ext.commands import has_permissions, MissingPermissions, CommandNotFound, BucketType, cooldown, CommandOnCooldown
from discord import Webhook, RequestsWebhookAdapter
from discord.ext.commands.core import check
from discord.utils import get
import logging
import random
import requests
import wikipedia
import asyncio
import time
import json
import sys
from PIL import Image
from io import BytesIO
from discord_components import *

client = commands.Bot(command_prefix= "%")
client.remove_command("help")

@client.event
async def on_ready():
    await client.change_presence(activity=discord.Activity(type=discord.ActivityType.listening, name="Volume 1"))
    print(f"---> Logged in as : {client.user.name} , ID : {client.user.id}")
    print(f"---> Total Servers : {len(client.guilds)}\n")
    DiscordComponents(client)
    
    # A Ping Commad
@client.command(name="ping")
async def ping(ctx: commands.Context):
    await ctx.send(f"Pong! {round(client.latency * 1000)}ms")
