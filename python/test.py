import time
from pathlib import Path
import yt_dlp

PLAYLIST_URL = "https://www.youtube.com/watch?v=CAneHUXYTfY&list=RDEMuOrlXeWFlpHo_X5DKdborw&start_radio=1"
OUTPUT_DIR = Path("salida_mp3")
ARCHIVE_FILE = OUTPUT_DIR / "descargando.txt"

OUTPUT_DIR.mkdir(parents=True, exist_ok=True)


def hook_progreso(d):
    if d["status"] == "downloading":
        total = d.get("total_bytes") or d.get("total_bytes_estimate")
        downloaded = d.get("downloaded_bytes", 0)
        speed = d.get("speed")
        eta = d.get("eta")

        if total:
            porcentaje = downloaded / total * 100
            barra_len = 30
            llenos = int(barra_len * downloaded / total)
            barra = " " * llenos + "-" * (barra_len - llenos)
            print(
                f"\r[{barra}] {porcentaje:6.2f}% | "
                f"{downloaded/1024/1024:7.2f} MB / {total/1024/1024:7.2f} MB | "
                f"Vel: {(speed/1024/1024):.2f} MB/s | ETA: {eta}s",
                end="",
                flush=True
            )
        else:
            print(
                f"\rDescargando... {downloaded/1024/1024:.2f} MB", end="", flush=True)

    elif d["status"] == "finished":
        print("\nDescarga completada. Convirtiendo a MP3...")


def main():
    ydl_opts = {
        "format": "bestaudio/best",
        "outtmpl": str(OUTPUT_DIR / "%(playlist_title)s/%(title)s.%(ext)s"),
        "ignoreerrors": True,
        "download_archive": str(ARCHIVE_FILE),
        "progress_hooks": [hook_progreso],
        "postprocessors": [
            {
                "key": "FFmpegExtractAudio",
                "preferredcodec": "mp3",
                "preferredquality": "320",
            }
        ],
        "quiet": True,
        "no_warnings": True,
        "extract_flat": True,
    }

    try:
        print("Obteniendo lista de videos...")

        with yt_dlp.YoutubeDL(ydl_opts) as ydl:
            info = ydl.extract_info(PLAYLIST_URL, download=False)

            entries = info.get("entries", [])

            print(f"Total de videos encontrados: {len(entries)}")

            ydl_opts["extract_flat"] = False

            with yt_dlp.YoutubeDL(ydl_opts) as ydl:
                for i, entry in enumerate(entries, start=1):
                    url = entry.get("url") or entry.get("webpage_url")

                    if not url:
                        continue

                    print(f"\n[{i}/{len(entries)}] Descargando: {url}")
                    try:
                        ydl.download([url])
                    except Exception as e:
                        print(f"Error: {e}")

                    print("Esperando 5 segundos antes del siguiente... ")
                    time.sleep(5)

            print("\nProceso finalizado.")
            print(f"Los MP3 se guardaron en: {OUTPUT_DIR.resolve()}")

    except Exception as e:
        print(f"\nOcurrio un error: {e}")


if __name__ == "__main__":
    main()
