CREATE TABLE contacts (
  id          IDENTITY,
  prefix      VARCHAR(8),
  first_name  VARCHAR(128),
  last_name   VARCHAR(128),
  email       VARCHAR(256),
  home_phone  VARCHAR(64)
);