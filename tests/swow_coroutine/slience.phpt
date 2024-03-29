--TEST--
swow_coroutine: slience
--SKIPIF--
<?php
require __DIR__ . '/../include/skipif.php';
?>
--FILE--
<?php
require __DIR__ . '/../include/bootstrap.php';

use Swow\Coroutine;

function foo(): void
{
    Coroutine::yield();
}

$coroutine = Coroutine::run(static function (): void {
    @foo();
});

trigger_error('foo', E_USER_WARNING);

$coroutine->resume();

echo "Done\n";
?>
--EXPECTF--
Warning: [Warning in main] %s
Stack trace:
#0 %s(%d): trigger_error('%s', %d)
#1 {main}
  triggered in %s on line %d
Done
