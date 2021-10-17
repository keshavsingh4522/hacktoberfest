using System;
using System.Threading;
using System.Threading.Tasks;
using CSRakowski.Parallel;
using CSRakowski.Parallel.Extensions;

namespace Examples
{
    public static class Program
    {
        public static async Task MainAsync()
        {
            List<string> fileUrls = GetFileUrls();

            var files = await fileUrls
                                .AsParallelAsync()
                                .WithMaxDegreeOfParallelism(8)
                                .WithOutOfOrderProcessing(false)
                                .ForEachAsync((url) =>
                                {
                                    return DownloadFileAsync(url);
                                });
        }

        private static List<string> GetFileUrls() => new List<string>();

        private static Task<string> DownloadFileAsync(string url) => Task.FromResult(url);
    }
}
