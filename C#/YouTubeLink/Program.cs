using System;
/// the URL  to a YouTube video has two format
/// 1- https://www.youtube.com/watch?v=zWh3CShX_do
/// 2- https://youtu.be/zWh3CShX_do
/// Write a function to extract a YouTube Id
/// Example above return zWh3CShX_do
namespace YouTubeLink
{
    class Program
    {
        static void Main(string[] args)
        {
                Console.Write("Enter YouTube URL:");
                string url = Console.ReadLine();
                Console.WriteLine($"YouTube Id:{ParseYouTubeId(url)}");
        }
    static string ParseYouTubeId(string url)
    {
        int equalsIndex = url.IndexOf("=");
        int forwardLastIndex = url.LastIndexOf("/");
        if (equalsIndex != -1)
        {
            return url.Substring(equalsIndex+1);
        }
        else if (forwardLastIndex!=-1)
        {
            return url.Substring(forwardLastIndex+1);
        }
        else
        {
            return "";
        }
    }
    }
}
