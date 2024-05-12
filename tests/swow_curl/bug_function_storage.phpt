--TEST--
swow_curl: callback function storage
--SKIPIF--
<?php
require __DIR__ . '/../include/skipif.php';
skip_if(PHP_SAPI !== 'cli', 'only for cli');
skip_if(!getenv('SWOW_HAVE_CURL') && !Swow\Extension::isBuiltWith('curl'), 'extension must be built with libcurl');
require __DIR__ . '/../include/bootstrap.php';
skip_if(!str_contains(@file_get_contents(TEST_WEBSITE1_URL), TEST_WEBSITE1_KEYWORD), 'Unable to access ' . TEST_WEBSITE1_URL);
skip_if(!str_contains(@file_get_contents(TEST_WEBSITE2_URL), TEST_WEBSITE2_KEYWORD), 'Unable to access ' . TEST_WEBSITE2_URL);
?>
--FILE--
<?php
require_once __DIR__ . '/../include/bootstrap.php';

$headerLines = [];
$headerFunction = function (CurlHandle $curl, string $headerLine) use (&$headerLines): int {
    $parts = explode(':', $headerLine, 2);
    if (count($parts) === 2) {
        $headerLines[strtolower($parts[0])] = trim($parts[1]);
    }
    return strlen($headerLine);
};
$curl = curl_init();
curl_setopt($curl, CURLOPT_URL, TEST_WEBSITE1_URL);
curl_setopt($curl, CURLOPT_HEADERFUNCTION, $headerFunction);
curl_setopt($curl, CURLOPT_RETURNTRANSFER, 1);
unset($headerFunction);
$response = curl_exec($curl);
Assert::contains($response, TEST_WEBSITE1_KEYWORD);
Assert::true(strtotime($headerLines['date']) > 0);
curl_close($curl);

echo "Done\n";
?>
--EXPECT--
Done
