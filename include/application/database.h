#pragma once

#include <sqlite3.h>

#include "application/filesystem.h"
#include "application/serial.h"
#include "config/seeder.h"
/**
 * Must have initialized SPIFFS beforehand
 */
namespace application::db {
static bool is_initialized = false;

class Database {
private:
    sqlite3* p_database = nullptr;
    String error_message;

public:
    Database() { };

    void init(const char* filename) {
        sqlite3_initialize();
        open_connection(filename);
    }

    int execute(const char* query, sqlite3_callback* callback = nullptr) {
        Serial.println("Running SQL Query: " + String(query));
        long start_time = micros();
        char* err;
        int resp_code =
            sqlite3_exec(p_database, query, *callback, nullptr, &err);
        if (resp_code != SQLITE_OK) {
            error_message = String(err);
            Serial.printf("SQL ERROR[%s]: %s\n", resp_code, error_message);
        } else {
            Serial.printf("SQL executed successfully.\n");
        }
        Serial.print(F("Time taken: "));
        Serial.println(micros() - start_time);
        return resp_code;
    }

    int open_connection(const char* filename) {
        int resp_code = sqlite3_open(filename, &p_database);
        if (resp_code) {
            error_message = sqlite3_errmsg(p_database);
            Serial.printf("ERROR: Can't open database: %s\n",
                          error_message.c_str());
        } else {
            Serial.printf("Database connection was successful.\n");
        }
        return resp_code;
    }

    void close_connection() {
        sqlite3_free(p_database);
    }

    const char* get_error() {
        return error_message.c_str();
    }

    void close() {
        close_connection();
        sqlite3_close(p_database);
    }

    ~Database(){
        close();
    };
};

static Database database;
const Database& setup_database() {
    if (!is_initialized) {
        database.init("/spiffs/main.db");
        seed_database();
        is_initialized = true;
    }
    return database;
};
}  // namespace application::db
