
flowchart TD
    A([Start]) --> B[Initialize Stack and Queue]
    B --> C[Display Main Menu]
    C --> D{Select Operation}

    D -->|1. Create Account| E[Create New Account Node]
    E --> F[Push Account into Stack]
    F --> C

    D -->|2. Add Transaction| G[Create Transaction Node]
    G --> H[Enqueue Transaction]
    H --> C

    D -->|3. Process Transaction| I{Queue Empty?}
    I -->|Yes| J[Display No Transactions]
    I -->|No| K[Dequeue Transaction]
    K --> L[Process Transaction]
    L --> C
    J --> C

    D -->|4. View Latest Account| M{Stack Empty?}
    M -->|Yes| N[Display No Accounts]
    M -->|No| O[Display Top Account]
    N --> C
    O --> C

    D -->|5. Exit| P([Stop])
    D -->|Invalid Choice| Q[Display Invalid Choice]
    Q --> C
