from kivy.uix.screenmanager import Screen
from kivymd.uix.label import MDLabel
from pytube import YouTube
import pytube
from kivymd.app import MDApp
from kivymd.uix.button import MDRectangleFlatButton
from kivymd.uix.textfield import MDTextField


class MainApp(MDApp):
    def build(self):
        screen = Screen()

        def download_video(url):
            if url != None:
                try:
                    my_video = YouTube(url)
                    print(my_video.title)
                    print(my_video.views)
                    print(my_video.author)
                    print(my_video.description)
                    print(my_video.thumbnail_url)
                    my_video = my_video.streams.get_highest_resolution()
                    st = []
                    title.text=my_video.title
                    # my_video.download()
                except pytube.exceptions.RegexMatchError:
                    print('The Regex pattern did not return any matches for the video: {}'.format(url))

                except pytube.exceptions.ExtractError:
                    print('An extraction error occurred for the video: {}'.format(url))

                except pytube.exceptions.VideoUnavailable:
                    print('The following video is unavailable: {}'.format(url))
        url = MDTextField(
            size_hint=(0.8, 1),
            hint_text= "Enter video Url",
            helper_text= "This will disappear when you click off",
            helper_text_mode= "on_error",
            on_text_validate=self.set_error_message,
            on_focus=self.set_error_message,
            pos_hint={"center_x": 0.5, "center_y": 0.5},
        )
        title = MDLabel(
        text= "",
        halign= "center",
        theme_text_color= "Custom",
        pos_hint={"center_x": 0.5, "center_y": 0.2},
        )
        screen.add_widget(
            MDRectangleFlatButton(
                text="Youtube Downloader",
                pos_hint={"center_x": 0.5, "center_y": 0.3},
                on_press = lambda x:download_video(url.text),
            ),
        )
        screen.add_widget(
            url
        )
        screen.add_widget(
            title
        )

        return screen
        # print(url.text)

    def set_error_message(self, instance_textfield):
        self.screen.ids.text_field_error.error = True



MainApp().run()




# print('Choose One: ')
# for stream in my_video.streams:
#     st.append(stream)
#     print(stream)
#
# ch = input()



