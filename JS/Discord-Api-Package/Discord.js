const fetch = require('node-fetch');
const { EventEmitter } = require('events');

const BASE_URL = 'https://discord.com/apis'

class Discord extends EventEmitter {
    constructor(options){
        super();

        let { token, version } = options;

        if(!token) throw new Error('token is missing or undefined');
        if(!version) version = 9;

        this.token = token;
        this.version = version;
    }
    async getAuditLog(options) {
            let { guild_id } = options;
            if(!guild_id) throw new Error('guild_id is missing or undefined');
            if(typeof guild_id !== "integer") throw new Error('guild_id must be an integer');
            this.id = guild_id;

            const URL = `${BASE_URL}/${this.version}/guilds/${this.id}/audit-logs`;
            const requestOptions = {
                method: "GET",
                headers:{
                    "Content-Type": "application/json",
                    "Authorization": `Bot ${this.token}`
                }
            }

            fetch(URL, requestOptions)
              .then(res => res.json())
              .then(json => {
                  console.log(json)
              })
    }
}