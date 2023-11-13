using System.Text;
using Cryptoanalysis;

Encoding.RegisterProvider(CodePagesEncodingProvider.Instance);
Cryptoanalyzer cryptoanalyzer = new ();
cryptoanalyzer.Init(Environment.GetCommandLineArgs()[1], 866);

int keyLength = int.Parse(Environment.GetCommandLineArgs()[2]);

// находим ключ
if (cryptoanalyzer.Decode(keyLength))
{
    cryptoanalyzer.PrintKey();
}
else
{
    Console.WriteLine("Key wasn't found");
}
