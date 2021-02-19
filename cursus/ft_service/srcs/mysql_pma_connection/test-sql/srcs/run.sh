mysql_install_db --user=root

mysqld --user=root --bootstrap < /tmp/init_db.sql

#telegraf 백그라운드 실행 & mysql 서버 데몬 실행
mysqld --user=root
