from kivy.uix.image import Image
from kivy.uix.screenmanager import Screen
from kivymd.uix.label import MDLabel
from pytube import YouTube
import pytube
from kivymd.app import MDApp
from kivymd.uix.button import MDFillRoundFlatButton
from kivymd.uix.textfield import MDTextField


class MainApp(MDApp):
    def build(self):
        screen = Screen()
        self.theme_cls.primary_palette="Pink"
        def download_video(url):
            if url != None:
                message.text = "Downloading..."
                try:
                    my_video = YouTube(url)
                    print(my_video.title)
                    print(my_video.views)
                    print(my_video.author)
                    print(my_video.description)
                    print(my_video.thumbnail_url)
                    my_video = my_video.streams.get_highest_resolution()

                    my_video.download('Media')

                    message.text ="Video Downloaded Successfully."
                except pytube.exceptions.RegexMatchError:
                    print('The Regex pattern did not return any matches for the video: {}'.format(url))

                except pytube.exceptions.ExtractError:
                    print('An extraction error occurred for the video: {}'.format(url))

                except pytube.exceptions.VideoUnavailable:
                    print('The following video is unavailable: {}'.format(url))
                # my_video.download()

        url = MDTextField(
            size_hint=(0.8, 1),
            hint_text= "Enter video Url",
            helper_text= "This will disappear when you click off",
            helper_text_mode= "on_error",
            on_text_validate=self.set_error_message,
            on_focus=self.set_error_message,
            pos_hint={"center_x": 0.5, "center_y": 0.5},
        )
        message = MDLabel(
        text= "",
        halign= "center",
        pos_hint={"center_x": 0.5, "center_y": 0.2},
        color= (0, 1, 0)
        )

        screen.add_widget(
            MDFillRoundFlatButton(
                text="Youtube Downloader",
                pos_hint={"center_x": 0.5, "center_y": 0.4},
                on_press = lambda x:download_video(url.text),
            ),
        )
        screen.add_widget(
            url

        )
        screen.add_widget(
            Image(
                source="logo.png",
                pos_hint={"center_x": 0.5, "center_y": 0.7},
                size_hint_x=0.3,
                size_hint_y=0.3
                  )
        )
        screen.add_widget(
            message
        )

        return screen
        

    def set_error_message(self, instance_textfield):
        self.screen.ids.text_field_error.error = True



MainApp().run()







