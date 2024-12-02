# API Documentation

## 1. AuthenticationController

### Endpoints

- **Login()**

  - **Description**: Authenticates a user.
  - **Input**: `username`, `password`
  - **Output**: `success`, `error_message`
- **Signup()**

  - **Description**: Registers a new user.
  - **Input**: `username`, `password`, `email`
  - **Output**: `success`, `user_id`

## 2. FileSystemController

### Endpoints

- **CreateFile()**

  - **Description**: Creates a new file.
  - **Input**: `path`, `content`
  - **Output**: `file_id`, `success`
- **ReadFile()**

  - **Description**: Reads content from a file.
  - **Input**: `file_id`
  - **Output**: `content`

## 3. SharingController

### Endpoints

- **SendFile()**
  - **Description**: Sends a file to another user.
  - **Input**: `file_id`, `recipient_id`
  - **Output**: `success`, `error_message`
