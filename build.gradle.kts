plugins {
    kotlin("multiplatform") version "1.9.23" apply false
    id("com.android.application") apply false
    id("com.android.library") apply false
}

allprojects {
    repositories {
        google()
        mavenCentral()
    }
}
