<?php

const MONTH_IN_SECONDS = 2592000;
const REDIS_ARRAY_POOL = [
    'redis1',
    'redis2',
    'redis3',
    'redis4',
    'redis5',
    'redis6',
    'redis7',
    'redis8',
    'redis9',
    'redis10',
];

ini_set('session.save_handler','redis');
ini_set('session.gc_maxlifetime', MONTH_IN_SECONDS);
session_save_path('tcp://redis:6379');