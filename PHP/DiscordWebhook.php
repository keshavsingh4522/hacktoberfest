<?php
/**
 * Discord Webhook
 * v1.2.0
 * Updated: 23.09.2019
 * www.magictm.com
 * (c) Marcin Stawowczyk 2019
 * License: MIT
 */
final class DiscordWebhook
{
    private $message;
    private $url;
    private $username = "www.magictm.com";
    private $avatar;
    private $embeds = [];
    private $tts;

    private $file;

    private $errors = [];

    /**
     * Set URL of the Webhook
     *
     * @param string $url
     */
    public function __construct(
        string $url = null
    )
    {
        $this->url = $url;
    }

    /**
     * Send Discord Webhook to the Discord server
     *
     * @return self
     */
    public function send()
    {
        if (!$this->validate()) {
          $errors = "";
          foreach ($this->errors as $key => $value) {
            $errors .= "$value";
          }
          throw new Exception("Zanim wyślesz wiadomość na Discorda popraw błędy: ". $errors);
        }

        $curl = curl_init();
        //timeouts - 5 seconds
        curl_setopt($curl, CURLOPT_TIMEOUT, 5); // 5 seconds
        curl_setopt($curl, CURLOPT_CONNECTTIMEOUT, 5); // 5 seconds
        curl_setopt($curl, CURLOPT_URL, $this->url);
        curl_setopt($curl, CURLOPT_POST, 1);
        curl_setopt($curl, CURLOPT_HTTPHEADER, array('Content-Type: application/json'));
        curl_setopt($curl, CURLOPT_RETURNTRANSFER, true);
        curl_setopt($curl, CURLOPT_SSL_VERIFYHOST, false);
        curl_setopt($curl, CURLOPT_SSL_VERIFYPEER, false);
        curl_setopt($curl, CURLOPT_POSTFIELDS, json_encode([
            'content' => $this->message,
            'username' => $this->username,
            'avatar_url' => $this->avatar,
            'tts' => $this->tts,
            'file' => $this->file,
            'embeds' => $this->embeds
        ]));
        $output = json_decode(
            curl_exec($curl),
            true
        );

        if (curl_getinfo($curl, CURLINFO_HTTP_CODE) != 204) {
            curl_close($curl);
            $message = "";

            if (!isset($output["message"])) {
              foreach ($output as $key => $value) {
                $message .= ucfirst($key) . " - " .$value[0];
              }
            } else {
              $message = $output["message"];
            }

            throw new Exception("Wystąpił błąd podczas przesyłania wiadomości na Discorda: " . $message);
        }
        curl_close($curl);

        return $this;
    }

    /**
     * Set message to send
     *
     * @param [type] $message
     * @return self
     */
    function setMessage($message) {
      $this->message = $message;
      return $this;
    }
    /**
     * Get message
     *
     * @return string
     */
    function getMessage() {
      return $this->message;
    }
    /**
     * Set URL
     *
     * @param string $url
     * @return self
     */
    function setURL($url) {
      $this->url = $url;
      return $this;
    }
    /**
     * Get URL
     *
     * @return string
     */
    function getURL() {
      return $this->url;
    }
    /**
     * Set username
     *
     * @param string $username
     * @return self
     */
    function setUsername($username) {
      $this->username = $username;
      return $this;
    }
    /**
     * Get username
     *
     * @return string
     */
    function getUsername() {
      return $this->username;
    }
    /**
     * Set avatar
     *
     * @param string $avatar
     * @return self
     */
    function setAvatar($avatar) {
      $this->avatar = $avatar;
      return $this;
    }
    /**
     * Get avatar
     *
     * @return string
     */
    function getAvatar() {
      return $this->avatar;
    }
    /**
     * Set
     *
     * @param object $file
     * @return self
     */
    function setFile($file) {
      $this->file = curl_file_create($file->getFile(), null, $file->getFileName());
      return $this;
    }

    /**
     * Get File that should be send to Discord
     *
     * @return void
     */
    function getFile() {
      return $this->file;
    }

    /**
     * Set TTS
     *
     * @param [type] $tts
     * @return void
     */
    function setTTS($tts) {
      $this->tts = $tts;
      return $this;
    }

    /**
     * Get TTS
     *
     * @return void
     */
    function getTTS() {
      return $this->tts;
    }

    /**
     * Reset all variables to its default values.
     *
     * @return self
     */
    function reset() {
      return $this;
    }

    /**
     * Set embed
     *
     * @param [type] $embed
     * @return void
     */
    function setEmbed($embed) {
      $this->embeds[] = $embed->toArray();

      return $this;
    }

    /**
     * Validate inputs before sending the webhook.
     *
     * @return void
     */
    private function validate() {

      if (!$this->url || $this->url === "") {
        $this->errors["url"] = "URL is empty.";
      }

      if (count($this->embeds) == 0) {
        if (!$this->message || $this->message === "") {
          $this->errors["message"] = "Message is empty.";
        } else if (strlen($this->message) >= 2000) {
          $this->errors["message"] = "Message is too long (max. 2000 characters).";
        }
      } else if ($this->message && strlen($this->message) >= 2000) {
        $this->errors["message"] = "Message is too long (max. 2000 characters).";
      }

      if (empty($this->errors)) {
        return true;
      }
      return false;
    }
}

?>
