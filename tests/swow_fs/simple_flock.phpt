--TEST--
swow_fs: simple flock
--FILE--
<?php
$file = sprintf('%s/testFlock.lock', sys_get_temp_dir());
var_dump($file);
if (is_file($file)) {
    unlink($file);
}
$h = fopen($file, 'w');
if (!$h) {
    exit('fopen failed');
}
echo ("try lock with LOCK_EX | LOCK_NB\n");
var_dump(flock($h, LOCK_EX | LOCK_NB));
fclose($h);
unlink($file);
?>
--EXPECTF--
string(%d) "%AtestFlock.lock"
try lock with LOCK_EX | LOCK_NB
bool(true)
