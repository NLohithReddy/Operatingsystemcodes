#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define ROLE_ADMIN 1
#define ROLE_USER 2
#define ROLE_GUEST 3

#define RESOURCE_DATA 1
#define RESOURCE_SETTINGS 2
#define RESOURCE_LOGS 3

struct User {
    char username[50];
    int role;
};

struct Resource {
    int type;
    char name[50];
};

bool checkAccess(struct User user, struct Resource resource) {
    if (user.role == ROLE_ADMIN) {
        return true;
    } else if (user.role == ROLE_USER) {
        if (resource.type == RESOURCE_DATA || resource.type == RESOURCE_SETTINGS) {
            return true;
        }
    }
    return false;
}

int main() {
    // Simulating current user and resource
    struct User currentUser;
    strcpy(currentUser.username, "Balakrishnan");
    currentUser.role = ROLE_USER;

    struct Resource currentResource;
    currentResource.type = RESOURCE_DATA;
    strcpy(currentResource.name, "Data file");

    // Checking access for the current user to the current resource
    if (checkAccess(currentUser, currentResource)) {
        printf("Access granted for user %s to resource %s.\n", currentUser.username, currentResource.name);
    } else {
        printf("Access denied for user %s to resource %s.\n", currentUser.username, currentResource.name);
    }

    return 0;
}

