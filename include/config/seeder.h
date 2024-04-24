#pragma once

#include "application/database.h"

namespace application::db {
bool seed_database() {
    Database database;
    database.init("/spiffs/main.db");
    // create users table
    database.execute(R"==(
        CREATE TABLE users (
            user_id int NOT NULL AUTO_INCREMENT,
            username varchar(25) NOT NULL,
            password varchar(30) NOT NULL,
            PRIMARY KEY (user_id)
        );
    )==");

    // add admin user
    database.(R"==(
        INSERT INTO users (username, password)
            VALUES ('admin', 'admin');
    )==");
    database.close();
    
    return true;
}
}
