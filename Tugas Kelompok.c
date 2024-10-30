#include <stdio.h>
#include <string.h>

// Fungsi untuk memproses transfer pulsa
int process_transfer(char *target_number, int amount) {
    // Simulasi saldo pengguna
    char users[][15] = {"08123456789", "08198765432"};
    int users_balance[] = {50000, 30000};  // Saldo pengguna

    // Cek jika nomor tujuan ada dan saldo cukup
    for (int i = 0; i < 2; i++) {
        if (strcmp(target_number, users[i]) == 0) {
            // Anggap pengguna adalah '08123456789'
            if (users_balance[0] >= amount) {
                users_balance[0] -= amount;
                users_balance[i] += amount;
                return 1;  // Transfer berhasil
            }
        }
    }
    return 0;  // Transfer gagal
}

// Fungsi utama untuk menampilkan menu
int main() {
    char target_number[15];
    int amount;
    char confirmation;

    printf("Menu Utama\n");
    printf("1. Transfer Pulsa\n");
    printf("Pilih menu: ");
    int choice;
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Masukkan Nomor Tujuan: ");
        scanf("%s", target_number);
        printf("Masukkan Jumlah Pulsa: ");
        scanf("%d", &amount);
        printf("Transfer ke %s sebesar %d\n", target_number, amount);
        printf("Konfirmasi Transfer (Y/N): ");
        scanf(" %c", &confirmation);  // Spasi sebelum %c untuk mengabaikan karakter newline

        if (confirmation == 'Y' || confirmation == 'y') {
            if (process_transfer(target_number, amount)) {
                printf("Transfer Berhasil\n");
            } else {
                printf("Transfer Gagal\n");
            }
        } else {
            printf("Transfer Dibatalkan\n");
        }
    }

    return 0;
}
