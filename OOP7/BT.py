from __future__ import annotations
from dataclasses import dataclass
from typing import Dict, List
import sys
#input = lambda: sys.stdin.buffer.readline().rstrip()
print = lambda x: sys.stdout.write(str(x) + '\n')
@dataclass
class CanBo:
    hoten: str
    tuoi: int
    gioitinh: str
    diachi: str
    loai: str
    def get_hoten(self) -> str:
        return self.hoten
    def get_loai(self) -> str:
        return self.loai
    def in_tt(self) -> None:
        print(f"Ho ten: {self.hoten}")
        print(f" | Tuoi: {self.tuoi}")
        print(f" | Gioi tinh: {self.gioitinh}")
        print(f" | Dia chi: {self.diachi}")
        print(f" | Loai: {self.loai}")
    def data(self) -> str:
        raise NotImplementedError
    def record(self) -> str:
        return (
            f"{self.hoten}|{self.tuoi}|{self.gioitinh}|"
            f"{self.diachi}|{self.loai}|{self.data()}"
        )
@dataclass
class CongNhan(CanBo):
    bac: int
    def __init__(self, ht: str, t: int, gt: str, dc: str, bac: int) -> None:
        super().__init__(ht, t, gt, dc, "Cong nhan")
        self.bac = bac
    def in_tt(self) -> None:
        super().in_tt()
        print(f" | Bac: {self.bac}/10")
    def data(self) -> str:
        return str(self.bac)

@dataclass
class KySu(CanBo):
    nganh: str
    def __init__(self, ht: str, t: int, gt: str, dc: str, nganh: str) -> None:
        super().__init__(ht, t, gt, dc, "Ky su")
        self.nganh = nganh
    def in_tt(self) -> None:
        super().in_tt()
        print(f" | Nganh dao tao: {self.nganh}")
    def data(self) -> str:
        return self.nganh

@dataclass
class NhanVien(CanBo):
    congviec: str
    def __init__(self, ht: str, t: int, gt: str, dc: str, congviec: str) -> None:
        super().__init__(ht, t, gt, dc, "Nhan vien")
        self.congviec = congviec
    def in_tt(self) -> None:
        super().in_tt()
        print(f" | Cong viec: {self.congviec}")
    def data(self) -> str:
        return self.congviec

class QLCB:
    def __init__(self) -> None:
        self.ds: Dict[str, CanBo] = {}
    @staticmethod
    
    def _split(line: str, delimiter: str = ",") -> List[str]:
        return [token.strip() for token in line.strip().split(delimiter)]
    @staticmethod
    
    def _tao_can_bo(tokens: List[str], raw_line: str) -> CanBo:
        if len(tokens) < 6:
            raise ValueError(f"Du lieu khong hop le: {raw_line}")
        ht = tokens[0]
        t = int(tokens[1])
        gt = tokens[2]
        dc = tokens[3]
        loai = tokens[4]
        tt_rieng = tokens[5]
        if loai == "Cong nhan":
            return CongNhan(ht, t, gt, dc, int(tt_rieng))
        if loai == "Ky su":
            return KySu(ht, t, gt, dc, tt_rieng)
        if loai == "Nhan vien":
            return NhanVien(ht, t, gt, dc, tt_rieng)
        raise ValueError(f"Loai can bo khong hop le: {loai}")

    def luujson(self, name: str) -> None:
        try:
            with open(name, "w", encoding="utf-8") as file:
                for hoten in sorted(self.ds):
                    file.write(self.ds[hoten].record() + "\n")
            print("Da luu xong file JSON.")
        except OSError:
            print("Loi: Khong the mo file de ghi.")

    def read_csv(self, name: str) -> None:
        try:
            with open(name, "r", encoding="utf-8") as file:
                for line in file:
                    line = line.rstrip("\n")
                    if not line or line.startswith("#"):
                        continue
                    try:
                        tokens = self._split(line)
                        cb = self._tao_can_bo(tokens, line)
                        self.ds[cb.get_hoten()] = cb
                    except ValueError as err:
                        print(f"Loi khi doc du lieu: {err}")
                    except Exception as err:  # pragma: no cover
                        print(f"Loi khong xac dinh: {err}")
        except FileNotFoundError:
            print(f"Loi: Khong tim thay file {name} (FileNotFoundError)")
            return
        print("Da doc xong file CSV.")

    def themcb(self, cb: CanBo) -> None:
        self.ds[cb.get_hoten()] = cb
        self.luujson("canbo.json")

    def xoacb(self, hoten: str) -> None:
        if hoten in self.ds:
            del self.ds[hoten]
            print(f"Da xoa can bo: {hoten}")
            self.luujson("canbo.json")
        else:
            print("Khong tim thay can bo de xoa.")

    def timcb(self, hoten: str) -> None:
        cb = self.ds.get(hoten)
        if cb is not None:
            cb.in_tt()
        else:
            print("Khong tim thay can bo.")

    def timloai(self, loai: str) -> None:
        alias = {
            "CongNhan": "Cong nhan",
            "KySu": "Ky su",
            "NhanVien": "Nhan vien",
        }
        loai = alias.get(loai, loai)

        found = False
        for cb in self.ds.values():
            if cb.get_loai() == loai:
                cb.in_tt()
                found = True
        if not found:
            print(f"Khong tim thay can bo loai {loai}.")

    def hiencb(self) -> None:
        if not self.ds:
            print("Danh sach trong.")
            return
        for hoten in sorted(self.ds):
            self.ds[hoten].in_tt()

    def taitufilejson(self, name: str) -> None:
        try:
            with open(name, "r", encoding="utf-8") as file:
                self.ds.clear()
                for line in file:
                    line = line.strip()
                    if not line:
                        continue
                    try:
                        tokens = self._split(line, "|")
                        cb = self._tao_can_bo(tokens, line)
                        self.ds[cb.get_hoten()] = cb
                    except ValueError as err:
                        print(err)
            print("Da tai xong file JSON.")
        except FileNotFoundError:
            print(f"Khong tim thay file JSON ({name}). Bat dau voi danh sach trong.")
        except Exception as err:
            print(f"Loi khi doc file JSON: {err}")


def main() -> None:
    qlcb = QLCB()
    qlcb.taitufilejson("canbo.json")

    while True:
        print("1. Doc du lieu tu file canbo.csv (Import)")
        print("2. Hien thi danh sach can bo hien tai")
        print("3. Them moi mot Cong Nhan")
        print("4. Xoa can bo theo Ho ten")
        print("5. Tim kiem theo Ho ten")
        print("6. Tim kiem theo Loai (CongNhan/KySu/NhanVien)")
        print("0. Thoat chuong trinh")
        print("====================================")

        raw = input("Nhap lua chon: ").strip()
        try:
            chon = int(raw)
        except ValueError:
            print("Nhap sai dinh dang. Vui long nhap so.")
            continue

        if chon == 1:
            qlcb.read_csv("canbo.csv")
            qlcb.luujson("canbo.json")
        elif chon == 2:
            qlcb.hiencb()
        elif chon == 3:
            try:
                ht = input("Nhap ho ten: ").strip()
                t = int(input("Nhap tuoi: ").strip())
                gt = input("Nhap gioi tinh: ").strip()
                dc = input("Nhap dia chi: ").strip()
                bac = int(input("Nhap bac (1-10): ").strip())
            except ValueError:
                print("Du lieu khong hop le. Vui long thu lai.")
                continue

            qlcb.themcb(CongNhan(ht, t, gt, dc, bac))
            print("Da them thanh cong!")
        elif chon == 4:
            ht = input("Nhap ho ten can xoa: ").strip()
            qlcb.xoacb(ht)
        elif chon == 5:
            ht = input("Nhap ho ten can tim: ").strip()
            qlcb.timcb(ht)
        elif chon == 6:
            loai = input("Nhap loai (CongNhan/KySu/NhanVien): ").strip()
            qlcb.timloai(loai)
        elif chon == 0:
            print("Thoat chuong trinh.")
            break
        else:
            print("Lua chon khong hop le. Vui long chon lai.")

if __name__ == "__main__":
    main()