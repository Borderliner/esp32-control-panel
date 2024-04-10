#pragma once

#include "system/database.h"

namespace application::db {
bool seed_database() {
    // create users table
    execute(R"==(
        CREATE TABLE users (
            user_id int NOT NULL AUTO_INCREMENT,
            username varchar(25) NOT NULL,
            password varchar(30) NOT NULL,
            PRIMARY KEY (user_id)
        );
    )==");

    // add admin user
    execute(R"==(
        INSERT INTO users (username, password)
            VALUES ('admin', 'admin');
    )==");

    return true;
}
}
