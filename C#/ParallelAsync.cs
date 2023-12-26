using System;
using System.Threading;
using System.Threading.Tasks;
using CSRakowski.Parallel;

namespace Examples
{
    public static class Program
    {
        public static async Task MainAsync()
        {
            List<string> fileUrls = GetFileUrls();

            var files = await ParallelAsync.ForEachAsync(fileUrls, (url) => {
                return DownloadFileAsync(url);
            }, maxBatchSize: 8, allowOutOfOrderProcessing: true);
        }

        private static List<string> GetFileUrls() => new List<string>();

        private static Task<string> DownloadFileAsync(string url) => Task.FromResult(url);
    }
}
