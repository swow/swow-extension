--TEST--
swow_coroutine: resume dead
--SKIPIF--
<?php
require __DIR__ . '/../include/skipif.php';
?>
--FILE--
<?php
require __DIR__ . '/../include/bootstrap.php';

$coroutine = new Swow\Coroutine(function () {
    echo 'End' . PHP_LF;
});
echo 'Resume' . PHP_LF;
$coroutine->resume();
echo 'Out' . PHP_LF;
$coroutine->resume();
echo 'Never here';

?>
--EXPECTF--
Resume
End
Out

Warning: [Fatal error in R1] Uncaught Swow\Coroutine\Exception: Coroutine is not available in %s:%d
Stack trace:
#0 %s(%d): Swow\Coroutine->resume()
#1 {main}
  thrown in %s on line %d
