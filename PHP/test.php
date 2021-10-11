<?php

namespace Onliner\Counter\Manager;

class VisitManager
{
    const DATE_FORMAT = 'Ymd';

    private $pdo;
    private $page;
    private $isVisitedToday;

    public function __construct(\PDO $pdo, $page)
    {
        $this->pdo = $pdo;
        $this->page = $page;
    }

    public function init(): void
    {
        $this->pdo->exec('
            CREATE TABLE IF NOT EXISTS page (
                id   INTEGER PRIMARY KEY,
                `date` data_type int,
                `visitors` data_type int DEFAULT 0
            );
        ');
    }

    public function isPageVisited(): bool
    {
        if ($this->isVisitedToday) {
            return $this->isVisitedToday;
        }

        $stmt = $this->pdo->prepare('SELECT * FROM page WHERE date = :currDate;');
        $stmt->execute([
            ':currDate' => date($this::DATE_FORMAT),
        ]);

        $this->isVisitedToday = (bool) $stmt->fetch(\PDO::FETCH_ASSOC);

        return $this->isVisitedToday;
    }

    public function getVisitors(): int
    {
        $stmt = $this->pdo->prepare('SELECT visitors FROM page WHERE date = :currDate;');
        $status = $stmt->execute([
            ':currDate' => date($this::DATE_FORMAT),
        ]);

        return $status ? (int) $stmt->fetchColumn(0) : 0;
    }

    public function getAllData(): array
    {
        $stmt = $this->pdo->prepare('SELECT * FROM page;');
        $stmt->execute();

        $data = [];
        while ($row = $stmt->fetch(\PDO::FETCH_ASSOC)) {
            $data[] = $row;
        }

        return $data;
    }

    public function visit()
    {
        if(!$this->isPageVisited()) {
            $stmt = $this->pdo->prepare('
                INSERT INTO page (date, visitors)
                VALUES(:date,	:visitors);
            ');

            $stmt->execute([
                ':date' => date($this::DATE_FORMAT),
                ':visitors' => 1,
            ]);
        } else {
            $stmt = $this->pdo->prepare('SELECT id, visitors FROM page WHERE date = :currDate;');
            $stmt->execute([
                ':currDate' => date($this::DATE_FORMAT),
            ]);

            $data = $stmt->fetch(\PDO::FETCH_ASSOC);

            $visits = (int) $data['visitors'];
            $visits++;

            $stmt = $this->pdo->prepare("UPDATE page SET visitors = :visitors WHERE id = :id;");
            $stmt->execute([
                ':id' => $data['id'],
                ':visitors' => $visits,
            ]);
        }
    }

    public function cleanup(): bool
    {
        $stmt = $this->pdo->prepare('
            DELETE FROM page
            WHERE id <= (
            SELECT id
            FROM (
                  SELECT id
                  FROM page
                  ORDER BY id DESC
                  LIMIT 1 OFFSET 1825
                ) ids
            )
          ');

        return $stmt->execute();
    }
}