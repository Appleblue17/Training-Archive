import glob
import json


def clean_log_file(path, keep=100):
    try:
        with open(path, "r", encoding="utf-8") as f:
            data = json.load(f)
        if not isinstance(data, list):
            print(f"[Log Cleaner] Skip {path}: not a list")
            return
        data_length = len(data)
        if len(data) > keep:
            data = data[-keep:]
            with open(path, "w", encoding="utf-8") as f:
                json.dump(data, f, ensure_ascii=True, indent=2)
            print(
                f"[Log Cleaner] Cleaned {path}: found {data_length} logs, kept last {keep} logs."
            )
        else:
            print(
                f"[Log Cleaner] {path}: found {data_length} logs, already <= {keep} logs."
            )
    except Exception as e:
        print(f"[Log Cleaner] Error processing {path}: {e}")


if __name__ == "__main__":
    print("[Log Cleaner] Starting log cleanup...")
    clean_log_file("crawler/global.log.json", keep=100)

    for path in glob.glob("crawler/*/log.json"):
        clean_log_file(path, keep=200)

    print("[Log Cleaner] Log cleanup completed.")
